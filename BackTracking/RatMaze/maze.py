from random import shuffle, randrange
import numpy as np

"""
1 - GENERA IL LABIRINTO
2 - CONVERTE IL LABIRINTO IN 2D ARRAY
3 - GENERA UNA STRINGA CORRISPONDENTE IN C (for lazy people)
"""


#genera una string con il labirinto
def make_maze(w=8, h=8):
    vis = [[0] * w + [1] for _ in range(h)] + [[1] * (w + 1)]
    ver = [["|  "] * w + ['|'] for _ in range(h)] + [[]]
    hor = [["+--"] * w + ['+'] for _ in range(h + 1)]

    def walk(x, y):
        vis[y][x] = 1

        d = [(x - 1, y), (x, y + 1), (x + 1, y), (x, y - 1)]
        shuffle(d)
        for (xx, yy) in d:
            if vis[yy][xx]:
                continue
            if xx == x:
                hor[max(y, yy)][x] = "+  "
            if yy == y:
                ver[y][max(x, xx)] = "   "
            walk(xx, yy)

    walk(randrange(w), randrange(h))

    s = ""
    for (a, b) in zip(hor, ver):
        s += ''.join(a + ['\n'] + b + ['\n'])
    return s


#genera dall labirinto un bitmap
def make_bitmap(maze : str):
    
    lineBitMap = []
    bitmap = []
    
    for idx in range( len(maze) ):
         
        if(maze[idx] == ' '):
            lineBitMap.append(1)
        
        elif(maze[idx] == '\n'):
            bitmap.append(lineBitMap)
            lineBitMap = []
        else:
            lineBitMap.append(0)

    bitmap = np.asarray(bitmap, np.matrix)
    bitmap = np.delete(bitmap, len(bitmap)-1 , 0  )

    def borderMaze(mazeWithBorder):
        #noTopBottomMaze
        nTB =  np.delete(mazeWithBorder, (0, len(mazeWithBorder) - 1), 0)
        #noBorderMaze
        for j in nTB:
            del j[0]
            del j[-1]
        #nB = np.delete(nTB, 0, 1)
        return nTB
   
    return borderMaze(bitmap).tolist()       

#genera una string che rappresenta la matrice utilizzabile direttamente in c lang
def lazyMe(btm):
    s = "{\n"
    for i in btm:
        s += "{"
        for j in i:
            s += str(j)
            s += ","

        s = s[:-1]
        s+= "},\n"
    s+= "}"

    return s



if __name__ == '__main__':
    
    #3 * k,2 * k -> per aver labirinti quadrati
    k = 5
    maze = make_maze(h = 3 * k, w = 2 * k)
    bmaze = make_bitmap(maze)

    print(maze)
    print( lazyMe(bmaze))


    print("Dimensione Y:", len(bmaze))
    print("Dimensione X:", len(bmaze[0]))
