void DFS_search(int n, int target) {
    for (int x = 0; x < n; x++) {
        if (!visited[x]) {
            visited[x] = 1;
            push(x);

            while (!isEmpty()) {
                int t = peek();

                if (t == target) {
                    printf("Found %d\n", target);
                    return;
                }

                int found = 0;

                for (int y = 0; y < n; y++) {
                    if (graph[t][y] == 1 && !visited[y]) {
                        visited[y] = 1;
                        push(y);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    pop();
                }
            }
        }
    }

    printf("Not found\n");
}
