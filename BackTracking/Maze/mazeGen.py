from random import shuffle, randrange
import numpy as np




#genera una labirinto
def make_maze(w, h):
    vis = [[0] * w + [1] for _ in range(h)] + [[1] * (w + 1)]
    ver = [["# "] * w + ['#'] for _ in range(h)] + [[]]
    hor = [["##"] * w + ['#'] for _ in range(h + 1)]

    def walk(x, y):
        vis[y][x] = 1

        d = [(x - 1, y), (x, y + 1), (x + 1, y), (x, y - 1)]
        shuffle(d)
        for (xx, yy) in d:
            if vis[yy][xx]:
                continue
            if xx == x:
                hor[max(y, yy)][x] = "# "
            if yy == y:
                ver[y][max(x, xx)] = "  "
            walk(xx, yy)

    walk(randrange(w), randrange(h))

    s = ""
    for (a, b) in zip(hor, ver):
        s += ''.join(a + ['\n'] + b + ['\n'])
    return s


if __name__ == '__main__':

    #linee e colonne
    l = 50
    c = 41
    maze = list(make_maze(h=l, w=c))
    
    maze[(2*c) + 2] = "I"
    maze[((2*c) + 2) * (2 * l) - 2] = "O"


    f = open("maze2.txt", "w")
    f.write( str( (2*l) + 1) + "\n")
    f.write( str( (2*c) + 1) + "\n")
    f.write("".join(maze))
    f.close()

    print("".join(maze))
    