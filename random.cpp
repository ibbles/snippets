#include <random>
#include <iostream>

// Goal:
// Create a uniform distribution of random numbers in a range.

class Die
{
public:
    Die(int num_sides)
        : m_generator(std::random_device()())
        , m_distribution(1, num_sides)
    {

    }

    int roll()
    {
        return m_distribution(m_generator);
    }

private:
    std::mt19937 m_generator;
    std::uniform_int_distribution<int> m_distribution;
};

int roll_die(int lower, int upper)
{
    // Seed.
    std::random_device device;
    unsigned int seed = device(); // Kinda like time(nullptr).

    // Pseudo-random generator.
    std::mt19937 generator(seed);

    // Distribution.
    std::uniform_int_distribution<int> distribution(lower, upper);

    return distribution(generator);
}


int main()
{
    Die d6(6);
    Die d20(20);
    for (int i = 0; i < 10; ++i)
    {
        std::cout << d20.roll() << ' ' << d6.roll() << '\n';
    }
}
