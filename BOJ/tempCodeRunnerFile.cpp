  int t1 = 0, t2 = 0;
        for (int i = 1; i <= n / 2; i++)
        {
            if (selected[i])
                for (int j = i + 1; j <= n / 2; j++)
                    if (selected[j])
                    {
                        t1 += arr[i][j];
                        t1 += arr[j][i];
                    }

            if (!selected[i])
                for (int j = i + 1; j <= n / 2; j++)
                    if (!selected[j])
                    {
                        t2 += arr[i][j];
                        t2 += arr[j][i];
                    }
        }
        result = min(abs(t1 - t2), result);
        return;