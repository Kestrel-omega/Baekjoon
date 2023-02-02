a=int(input())
b=int(input())

c=a*(b%10)
d=a*((b//10)%10)
e=a*((b//100)%10)
f=c+d*10+e*100

print(c)
print(d)
print(e)
print(f)
