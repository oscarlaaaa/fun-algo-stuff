## 2023-02-12 (DFS)
class Solution:
    def minimumFuelCost(self, roads: List[List[int]], seats: int) -> int:
        """
        input: n-1 bidirectional edges and the number of seats
        output: min litres of fuel for every representative to reach the capital

        notes:
        - each edge = 1 litre of fuel to travel
        - representatives of a city can ride with another representative if they
          have space
        - tree so guaranteed no cycles
        - can we travel outwards from node 0?
            - maybe count how many cities a path would take, and the number of
              representatives along the way / seats would be the litres needed?
            - BFS seems like an easy way to process step by step
        - we can also DFS to resolve from the ends inward
            - return tuples of (passenger count, litres used)
            - before returning, sum up passengers of all branches, add one to passenger count,
              add ceil(passengers/seats) litres to the tuple, and send back up
        
        analysis:
        - time = O(e) where e = num of roads
        - space = O(e) where e = num of roads
        """

        connections = [[] for _ in range(len(roads)+1)]
        for city_a, city_b in roads:
            connections[city_a].append(city_b)
            connections[city_b].append(city_a)
        
        def sumFuel(connections, seats, city, seen):
            seen.add(city)
            passenger_count, fuel_used = 1, 0
            for neighbour in connections[city]:
                if neighbour in seen:
                    continue
                
                count, fuel = sumFuel(connections, seats, neighbour, seen)
                passenger_count += count
                fuel_used += fuel

            ## don't use more gas if we're already at city 0
            if city != 0:
                fuel_used += ceil(passenger_count/seats)

            return (passenger_count, fuel_used)

        _, fuel = sumFuel(connections, seats, 0, set())
        return fuel
