key = input().lower()
passage = input().lower()
L = passage.split()
cnt = 0
origin = ' {} '.format(passage).find(' {} '.format(key))

if origin == -1:
    print(-1)
else:
    for word in L:
        if word == key:
            cnt += 1
    print(cnt, origin)
