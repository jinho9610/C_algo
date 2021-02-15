sort(answers.begin(), answers.end());

    for (auto answer : answers)
    {
        for (auto a : answer)
            cout << a << ' ';
        cout << '\n';
    }