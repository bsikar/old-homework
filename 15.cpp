#include <bits/stdc++.h>

int main() {
    std::vector<int> scores;

    for (int i = 0; i < 5; ++i) {
        int input;
        std::cin >> input;
        scores.push_back(input);
    }

    std::sort(scores.begin(), scores.end());

    scores.erase(scores.begin());
    scores.pop_back();

    float average = 0.;
    for (int i = 0; i < scores.size(); ++i) {
        average += scores.at(i);
    }
    average /= scores.size();

    std::cout << "Average: " << average << std::endl;

    return 0;
}
