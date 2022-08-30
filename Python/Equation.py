def main(naame):
    
    ask = int(input(f'''Hello {naame} ,
We solve Linear equations with 2 variables as well as Quadratic equations
Which would you like to solve :

1.) Linear Equations with 2 variables
2.) Quadratic Equations 

(For Linear equations with 2 variables , Enter '1')
(For Quadratic Equations , Enter '2' )\n\n'''))
    
    if ask == 1 :

        print('''This is a Linear Equation ( 2 Variables ) solver
        "a"X + "b"Y = c
        "d"X + "e"Y = f
    Enter the values of a , b , c , d , e and f\n''')

        a=float(input("Enter the value for 'a':\t"))
        b=float(input("Enter the value for 'b':\t"))
        c=float(input("Enter the value for 'c':\t"))
        d=float(input("Enter the value for 'd':\t"))
        e=float(input("Enter the value for 'e':\t"))
        f=float(input("Enter the value for 'f':\t"))

        result1 = eqSolv(a,b,c,d,e,f)

        print(result1)
    
    
    elif ask == 2 :
    
        print('''This is a Quadratic Equation Solver

        "A"X^2 + "B"X + C = 0
        Enter the values of A , B and C\n''')

        A = float(input("Enter the value for 'A':\t"))
        B = float(input("Enter the value for 'B':\t"))
        C = float(input("Enter the value for 'C':\t"))

        result2 = quadEqSolv(A,B,C)
        print(result2)
    
    
    else : 
        print("We dont solve that here ")


def eqSolv(a,b,c,d,e,f):

    print(f"Your equations are\n({a})X + ({b})Y =({c})\n and\n({d})X + ({e})Y = ({f}) ")

    x = (b*f - c*e)/(b*d - a*e)
    y = (c*d - a*f )/(b*d - a*e)

    return f"\nThe value of 'X' is ({x}) and 'Y' is ({y}) "

def quadEqSolv(A,B,C):
    from math import sqrt

    print(f"Your equation is\n({A})X^2 + ({B})X + ({C}) = 0")
    
    try: 
        x1 = ( - B + sqrt(B*B - 4*A*C) ) / 2*A
        x2 = ( - B - sqrt(B*B - 4*A*C) ) / 2*A
        
        return f"The values of 'X' for this equation are ({x1}) and ({x2}) " 
    except ValueError:
        print("The output cannot be generated for these inputed values in this equation")
    

if __name__ == "__main__" :
    
    naame = input("Enter Your name\n")
    
    ans = True
    
    while ans:
        
        main(naame)
        
        choice = input("do you want to continue? [Y/N]: ")
        
        if choice.lower() == 'y':
            ans = True
        elif choice.lower() == 'n':
            ans = False