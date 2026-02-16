#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 5000

// ---------- Node Structure ----------
typedef struct Node {
    char token[5];  // can store normal char or "##"
    int freq;
    struct Node *left, *right;
} Node;

// ---------- Heap (Priority Queue) ----------
Node* heap[MAX];
int heapSize = 0;

// Compare nodes for priority queue
int cmp(Node* a, Node* b) {
    if (a->freq != b->freq) 
        return a->freq < b->freq;
    return strcmp(a->token, b->token) < 0;  // ASCII priority
}

void heapPush(Node* x) {
    heap[++heapSize] = x;
    int i = heapSize;
    while (i > 1 && cmp(heap[i], heap[i/2])) {
        Node* temp = heap[i]; heap[i] = heap[i/2]; heap[i/2] = temp;
        i /= 2;
    }
}

Node* heapPop() {
    Node* ret = heap[1];
    heap[1] = heap[heapSize--];

    int i = 1;
    while (1) {
        int l = i*2, r = i*2+1, smallest = i;
        if (l <= heapSize && cmp(heap[l], heap[smallest])) smallest = l;
        if (r <= heapSize && cmp(heap[r], heap[smallest])) smallest = r;
        if (smallest == i) break;
        Node* temp = heap[i]; heap[i] = heap[smallest]; heap[smallest] = temp;
        i = smallest;
    }
    return ret;
}

// ---------- Dictionary for storing codes ----------
char dict_token[300][5];
char dict_code[300][100];
int dict_count = 0;

// ---------- Generate Codes ----------
void generateCodes(Node* root, char* code) {
    if (!root->left && !root->right) {
        strcpy(dict_token[dict_count], root->token);
        strcpy(dict_code[dict_count], code);
        dict_count++;
        return;
    }
    int len = strlen(code);

    char leftCode[100];
    char rightCode[100];

    strcpy(leftCode, code);
    strcpy(rightCode, code);

    leftCode[len] = '0'; leftCode[len+1] = '\0';
    rightCode[len] = '1'; rightCode[len+1] = '\0';

    generateCodes(root->left, leftCode);
    generateCodes(root->right, rightCode);
}

// Lookup code
char* getCode(char* token) {
    for (int i = 0; i < dict_count; i++)
        if (strcmp(dict_token[i], token) == 0)
            return dict_code[i];
    return "?";
}

// ---------- Helper ----------
int isVowel(char c) {
    return strchr("aeiouAEIOU", c) != NULL;
}

int main() {
    char s[MAX];
    fgets(s, MAX, stdin);
    s[strcspn(s, "\n")] = 0;

    int n = strlen(s);
    
    // ---------- TOKENIZE STRING (handle "##") ----------
    char tokens[MAX][5];
    int tokCount = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '#' && s[i+1] == '#') {
            strcpy(tokens[tokCount++], "##");
            i++;
        } else {
            tokens[tokCount][0] = s[i];
            tokens[tokCount][1] = '\0';
            tokCount++;
        }
    }

    // ---------- FREQUENCY MAP ----------
    char uniq[300][5];
    int freq[300];
    int ucount = 0;

    for (int i = 0; i < tokCount; i++) {
        int found = 0;
        for (int j = 0; j < ucount; j++) {
            if (strcmp(tokens[i], uniq[j]) == 0) {
                freq[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(uniq[ucount], tokens[i]);
            freq[ucount] = 1;
            ucount++;
        }
    }

    // Apply vowel rule
    for (int i = 0; i < ucount; i++) {
        if (strlen(uniq[i]) == 1 && isVowel(uniq[i][0]))
            freq[i] *= 2;
    }

    // ---------- BUILD HUFFMAN TREE ----------
    for (int i = 0; i < ucount; i++) {
        Node* nn = (Node*)malloc(sizeof(Node));
        strcpy(nn->token, uniq[i]);
        nn->freq = freq[i];
        nn->left = nn->right = NULL;
        heapPush(nn);
    }

    while (heapSize > 1) {
        Node* a = heapPop();
        Node* b = heapPop();

        Node* parent = (Node*)malloc(sizeof(Node));
        strcpy(parent->token, "~"); // internal node
        parent->freq = a->freq + b->freq;
        parent->left = a;
        parent->right = b;

        heapPush(parent);
    }

    Node* root = heapPop();

    // ---------- Generate Huffman Codes ----------
    char empty[5] = "";
    generateCodes(root, empty);

    // ---------- PROCESS QUERIES ----------
    int q;
    scanf("%d", &q);

    while (q--) {
        char type;
        scanf(" %c", &type);

        if (type == 'A') {
            // print encoded string
            for (int i = 0; i < tokCount; i++)
                printf("%s ", getCode(tokens[i]));
            printf("\n");
        }

        else if (type == 'B') {
            for (int i = 0; i < ucount; i++)
                printf("%s->%d, ", uniq[i], freq[i]);
            printf("\n");
        }

        else if (type == 'C') {
            char ch[5];
            scanf("%s", ch);
            printf("%s -> %s\n", ch, getCode(ch));
        }

        else if (type == 'D') {
            char ch[5];
            scanf("%s", ch);
            for (int i = 0; i < ucount; i++)
                if (strcmp(ch, uniq[i]) == 0)
                    printf("%s -> %d\n", ch, freq[i] / (isVowel(ch[0]) ? 2 : 1));
        }
    }

    return 0;
}
