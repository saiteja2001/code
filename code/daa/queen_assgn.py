n = int(input())

q = [[0 for i in range(n)] for i in range(n)]
def print_arr(q,n):
    for i in range(n):
        for j in range(n):
            print(q[i][j],end=" ")
        print()
    print("-------------------------")

def safe(q,n,x,y):
    for i in range(x):
        if q[i][y]==1:
            return False
    
    row=x-1
    col=y-1
    while row>=0 and col>=0:
        if q[row][col]==1:
            return False
        row-=1
        col-=1

        
    row = x
    col=y
    while row>=0 and col<n:
        if q[row][col]==1:
            return False
        row-=1
        col+=1
    
    return True


def fill(q,n,x):
    if n==x:
        print_arr(q,n)
    
    else:
        for i in range(n):
            if safe(q,n,x,i):
                q[x][i]=1
                fill(q,n,x+1)
                q[x][i]=0


fill(q,n,0)