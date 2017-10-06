# lem-in

Lem-in is a program that parses a text "anthill" composed of rooms and tunnels, and finds the shortest path between a start and end room.

## Rules

+ All N ants start in one room.
+ Rooms can be connected to 0 or more other rooms with two-way tunnels.
+ Each room can hold one ant at a time.
+ Start and End room can hold any number of ants.
+ Each turn, each ant can move to an adjacent room.

## Solving
I parsed the file as an unweighed undirected graph and used a modified Djikstra's algorithm to traverse it.  
The shortest paths are isolated and chosen depending on the number of ants, number of access tunnels to the exit rooms.  
The goal is to avoid bottlenecks as much as possible by distributing the ants appropriately.  

## File and Output format

### File

```
[number of ants]

#rooms :
[##start] || [##end] || []          #defines if the following room is the start or the end
[room name][room_x][room_y]         #room_x and room_y are not used
...

#connections :
[room_a]-[room_b]
...

```

### Output

```
#one line = one turn
L[ant number]-[destination name] L[ant number]-[destination name] ...
```

## Examples 

![](https://i.imgur.com/gQBLFpu.png)
![](https://i.imgur.com/zrEx01N.png)
![](https://i.imgur.com/tutoT4a.png)
