mod = 1000000007

r = raw_input().split()
n = int(r[0])
m = int(r[1])

x =  pow(2,m,mod)-1
res = pow(x,n,mod)
print res

# Each gift can be placed to any boxes, so there is 2^m possibilities to place gift i.
# But one of that possibilities is not allowed, which is not placing gift i in any box.
# So for each gift there is 2^m - 1 possibilities to pick which box to place.
# The total possibilities is the number of ways to place one gift ^ number of gifts.