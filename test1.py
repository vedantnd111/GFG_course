n=input()
def f(k):
    s=(n+1)//2;m=n
    while s>0 and m:
        l=min(k,m);s-=l;m-=l;m-=m//10
    return s<=0
l=[0,n]
while l[1]-l[0]>1:
    m=sum(l)//2;l[f(m)]=m
print(l[1])

# import re
# x="Derivatives are better than Fixed income"
# y=re.match(r'(.*) are (.*?).*',x,re.M | re.I)
# if y:
#     print("sum :",y.group())
#     print("run : ",y.group(1))
#     print("fun : ",y.group(2))
# else:
#     print("Why!")

# def fun(a,b=[]):
#     b.append(b.append(a))
#     return b

# for a in range(3):
#     res=fun(a)
# print(res) 



def m(var):
    try:
        return int(var)

    except ValueError, Argument:
        print("Invalid form->",Argument)

m("Run");
