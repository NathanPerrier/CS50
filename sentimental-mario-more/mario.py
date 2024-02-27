
while True:
    height = input("Height: ")  # get the  input and sets it to the variable height
    try:
        height = int(height)    # convert to integer
        if isinstance(height, int):     # if height is a integer
            if height >= 1 and height <= 8:     # if the height is more than 1 and less than 8 it will break the loop
                break
    except:
        pass

column = 1
while height > 0:   # while height is greater than 0
    height -= 1     # height - 1
    print(' '*height + '#'*column + '  ' + '#'*column)      # print the two triangles
    column += 1