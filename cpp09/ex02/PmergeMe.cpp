#include "PmergeMe.hpp"
std::vector<std::string> splitString(const std::string &str, char delimiter)
{
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    int i = 0;
    while (std::getline(ss, token, delimiter))
    {
        if (token.empty())
            i++;
        else
        {
            tokens.push_back(token);
            i++;
        }
    }
    return tokens;
}

int parse_int(const char *str, int *result)
{
    char *end;
    long val;
    errno = 0;
    val = strtol(str, &end, 10);
    if (errno == ERANGE || val > INT_MAX)
        return 0;

    if (*end != '\0')
        return 0;
    *result = (int)val;
    return 1;
}

std::vector<int> Ford_jhonson(std::vector<int> &numbersV)
{
    int leftover = -1;
    std::vector<std::pair<int, int> > pairs;
    std::vector<std::pair<int, int> > pend;
    std::vector<int> mc;
    std::vector<int> Sq;
    if (numbersV.size() == 1)
        return numbersV;

    for (size_t i = 0; i + 1 < numbersV.size(); i += 2)
    {
        if (numbersV[i] < numbersV[i + 1])
            pairs.push_back(std::make_pair(numbersV[i], numbersV[i + 1]));
        else
            pairs.push_back(std::make_pair(numbersV[i+1], numbersV[i]));
    }

    if (numbersV.size() % 2 != 0)
        leftover = numbersV.back();

    for (size_t i = 0; i < pairs.size(); i++)
    {
        mc.push_back(pairs[i].second);
        pend.push_back(std::make_pair(pairs[i].second, pairs[i].first));
    }

    mc = Ford_jhonson(mc);
    Sq = jacobSthal<std::vector<int> >(pend.size());
    int idx = 0;
    for (size_t i = 0; i < Sq.size(); i++)
    {
        if (Sq.size() > 2)
            idx = Sq[i] - 1;
        else
            idx = i;

        if (idx < (int)pend.size())
        {
            std::vector<int>::iterator bound = std::lower_bound(mc.begin(), mc.end(), pend[idx].first);
            std::vector<int>::iterator it = std::lower_bound(mc.begin(), bound, pend[idx].second);
            mc.insert(it, pend[idx].second);
        }
    }
    if (leftover != -1)
    {
        std::vector<int>::iterator it = std::lower_bound(mc.begin(), mc.end(), leftover);
        mc.insert(it, leftover);
    }
    return mc;
}
std::deque<int> Ford_jhonson_D(std::deque<int> &numbersD)
{
    int leftover = -1;
    std::deque<std::pair<int, int> > pairs;
    std::deque<std::pair<int, int> > pend;
    std::deque<int> mc;
    std::deque<int> Sq;
    if (numbersD.size() == 1)
        return numbersD;

    for (size_t i = 0; i + 1 < numbersD.size(); i += 2)
    {
        if (numbersD[i] < numbersD[i + 1])
            pairs.push_back(std::make_pair(numbersD[i], numbersD[i + 1]));
        else
            pairs.push_back(std::make_pair(numbersD[i+1], numbersD[i]));
    }

    if (numbersD.size() % 2 != 0)
        leftover = numbersD.back();

    for (size_t i = 0; i < pairs.size(); i++)
    {
        mc.push_back(pairs[i].second);
        pend.push_back(std::make_pair(pairs[i].second, pairs[i].first));
    }

    mc = Ford_jhonson_D(mc);
    Sq = jacobSthal<std::deque<int> >(pend.size());
    int idx = 0;
    for (size_t i = 0; i < Sq.size(); i++)
    {
        if (Sq.size() > 2)
            idx = Sq[i] - 1;
        else
            idx = i;

        if (idx < (int)pend.size())
        {
            std::deque<int>::iterator bound = std::lower_bound(mc.begin(), mc.end(), pend[idx].first);
            std::deque<int>::iterator it = std::lower_bound(mc.begin(), bound, pend[idx].second);
            mc.insert(it, pend[idx].second);
        }
    }
    if (leftover != -1)
    {
        std::deque<int>::iterator it = std::lower_bound(mc.begin(), mc.end(), leftover);
        mc.insert(it, leftover);
    }
    return mc;
}

