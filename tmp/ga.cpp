#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <random>

class City {
public:
    int id;
    double x;
    double y;

    double distanceTo(const City& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return std::sqrt(dx * dx + dy * dy);
    }
};

class Tour {
public:
    std::vector<City> cities;

    double getDistance() const {
        double total = 0.0;
        for (size_t i = 0; i < cities.size(); ++i) {
            total += cities[i].distanceTo(cities[(i + 1) % cities.size()]);
        }
        return total;
    }
};

std::vector<City> parseTSPFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<City> cities;
    std::string line;
    bool readCoordinates = false;

    while (std::getline(file, line)) {
        if (line == "EOF") break;

        if (readCoordinates) {
            std::stringstream ss(line);
            City city;
            ss >> city.id >> city.x >> city.y;
            cities.push_back(city);
        }

        if (line == "NODE_COORD_SECTION") {
            readCoordinates = true;
        }
    }

    return cities;
}

class GeneticAlgorithm {
public:
    std::vector<Tour> population;
    std::mt19937 rng;

    GeneticAlgorithm(const std::vector<City>& cities, int populationSize) {
        std::random_device rd;
        rng = std::mt19937(rd());
        for (int i = 0; i < populationSize; ++i) {
            Tour tour;
            tour.cities = cities;
            std::shuffle(tour.cities.begin(), tour.cities.end(), rng);
            population.push_back(tour);
        }
    }

    Tour& selectParent() {
        std::uniform_real_distribution<double> dist(0.0, 1.0);
        double r = dist(rng);
        double sum = 0.0;
        for (Tour& tour : population) {
            sum += 1.0 / tour.getDistance();
            if (r <= sum) {
                return tour;
            }
        }
        return population.back();
    }

    Tour crossover(const Tour& parent1, const Tour& parent2) {
        std::uniform_int_distribution<size_t> dist(0, parent1.cities.size() - 1);
        size_t start = dist(rng);
        size_t end = dist(rng);
        if (start > end) std::swap(start, end);

        Tour child;
        for (size_t i = start; i <= end; ++i) {
            child.cities.push_back(parent1.cities[i]);
        }

        for (const City& city : parent2.cities) {
            if (std::find(child.cities.begin(), child.cities.end(), city) == child.cities.end()) {
                child.cities.push_back(city);
            }
        }

        return child;
    }

    void mutate(Tour& tour) {
        std::uniform_int_distribution<size_t> dist(0, tour.cities.size() - 1);
        size_t i = dist(rng);
        size_t j = dist(rng);
        std::swap(tour.cities[i], tour.cities[j]);
    }

    void run(int generations) {
        for (int i = 0; i < generations; ++i) {
            std::vector<Tour> newPopulation;
            for (size_t j = 0; j < population.size(); ++j) {
                Tour& parent1 = selectParent();
                Tour& parent2 = selectParent();
                Tour child = crossover(parent1, parent2);
                mutate(child);
                newPopulation.push_back(child);
            }
            population = newPopulation;

            // Print the distance of the best tour in this generation
            auto bestTour = std::min_element(population.begin(), population.end(),
                                             [](const Tour& a, const Tour& b) { return a.getDistance() < b.getDistance(); });
            std::cout << "Generation " << (i + 1) << ": " << bestTour->getDistance() << std::endl;
        }
    }
};

int main() {
    std::vector<City> cities = parseTSPFile("a280.tsp");
    GeneticAlgorithm ga(cities, 50);
    ga.run(100);
    return 0;
}
