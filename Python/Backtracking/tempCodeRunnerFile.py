for i in range(len(result)):
        print(f'Solution {i}: ')
        for j in range(0, n*n):
            print(result[i][j], end =" ")
            if (j + 1) % n == 0: print(end='\n')
        print('\n')