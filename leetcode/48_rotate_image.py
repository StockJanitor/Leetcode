
def rotate(matrix: list[list[int]]) -> None:
    """
    Do not return anything, modify matrix in-place instead.
    """
    # length of matrix
    N = len(matrix)
    
    #transpose the matrix
    for i in range(N):
        for j in range(i):
            matrix[i][j], matrix[j][i] = matrix[j][i],matrix[i][j]

    # reverse each segment
    for r in matrix:
        r.reverse()