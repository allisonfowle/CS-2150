/*!
 * @author Allison Fowle
 * @date 11/29/2021
 * @detail CS 2150 - acf6nb
 **/


//code from travelling-skeleton.cpp for inlab!!!
#include <iostream>
#include <cstdlib>
#include <algorithm> //includes STL functions

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth& me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);



    //YOUR CODE HERE
    //start city shouldn't be permuted
    string start = dests[0]; //index the start city at the first city in dests
    
    //this is skeleton code from example on using next permuation and do/while
    //https://en.cppreference.com/w/cpp/algorithm/next_permutation
    sort(dests.begin() + 1, dests.end()); // sort beginning (not including start) to end
    float dist = 0.0; //temp dist variable
    float min = computeDistance(me, dests[0], dests); //computes distance
    vector<string> temp = dests; //temporary vector of strings
    do {
        dist = computeDistance(me, dests[0], dests); //set dist = computeDistance
        if (dist < min) { //if distance is less than min constant set above
            min = dist; //set the new lower distance = to min
            temp = dests; //keep track of destinations
        }
    } while (next_permutation(dests.begin() + 1, dests.end())); //parse through dests

    dests[0] = temp[0];
    cout << "Minimum path has distance " << min << ": ";
    printRoute(dests[0], temp);
    //cout << endl;

    return 0;
}


/**
 * @brief calculate distance from start to end of list
 * 
 * This method will compute the full distance of the cycle that starts
 * at the 'start' parameter, goes to each of the cities in the dests
 * vector IN ORDER, and ends back at the 'start' parameter.
 * 
 * @return float - total distance from start to all cities
 * @param me list of cities in Middle Earth
 * @param start what city to start the calculation at
 * @param dests list of cities
 */ 
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) {
    float total = 0.0; //variable we're going to add distance onto
    string start1 = start; //dummy variable for start because we don't want to change the parameter
    for (int i = 0; i < dests.size(); i++) {//5 spots in vector includes 0. size - 1
        total += me.getDistance(start1, dests[i]);
        start1 = dests[i];

        //old code: originally had a while loop with base cases. this didn't work because
        //I wasn't adding onto the distance as I calculated it
        // if (i == dests.size() - 1) {//if you've reached the end of dests vector, calculate distance
        //     //of dests[i] (which should be the last city) and the start location)
        //     me.getDistance(dests[i], dests[0]);
        // }
        // else {//if we're not thru the dests size, calculate distance of iteration i
        //     //and i + 1, to get first city and the city next to it
        //     me.getDistance(dests[i], dests[i + 1]);
        //     i++;//increment counter
        // }
    } 
    total += me.getDistance(dests[0], dests.back()); //TA said to use .back() here because it works on the last element of a vector?
    return total;
}



/**
 * @brief prints entire rouote, starting and ending at the 'start' parameter
 * 
 * The output should be similar to:
 * Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
 * 
 * @return void
 * @param start where the list of cities start
 * @param dests list of cities
 */ 
void printRoute(const string& start, const vector<string>& dests) {
    //counter for while loop
    int i = 0; 
    //while counter is less than the size of destinations
    while (i < dests.size()) {
        cout << dests[i] << " -> " ; //print destination of index i
        i++; //increment
    }
    cout << start << endl; //prints out the start city so you know you're done
}