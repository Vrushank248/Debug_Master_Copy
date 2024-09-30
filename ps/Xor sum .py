a = int( input( ), 2 )
b = int( input( ), 2 )
r = 0

for i in range( 314160 ):
    r += a ^ b
    b *= 2

print( (r % (10**9+7)) )