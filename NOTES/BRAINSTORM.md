fn main
main|IN {u64}
main|OUT {array[u64]}
main(arg) =
    for (int i = 0; i < 5; i++) {
        OUT[i] = arg + 1;
    }
end





fn magnitude
magnitude|IN {u64, u64}
magnitude|OUT {f64}
magnitude(x, y) =
    OUT = sqrt((x * x) + (y * y))
end





fn print
print|IN {string}
print|OUT {IO}



USE

print(magnitude(3, 4))






-----------------------------------------------

fn magnitude :: {u64, u64} -> {f64}

magnitude(x, y) =
    OUT = sqrt((x * x) + (y * y))
end



im not too sure about this:
consider multiple inputs or outputs being IN[0] or IN[1] or OUT[0] like multi dimentional input/output idk this is freaky
-----------------------------------------------

fn foo :: {array[u64]} -> {bool}

foo([1,2,3]) =
    for (i in IN) do
        if (x > 1) do
            OUT = True
        end
        else do
            OUT = False
        end
    end
end

foo([1,2,3]) =
    for (i in IN) do
        if (x > 1) then OUT = True
        else OUT = False end
    end
end



# consider
consider like the general input/output like multiple outputs possible with OUT[n] keyword; like multiple dimentional output is a part
of the language rather than having to understand the nesting that you usually have to.

i do not really want to do the :: syntax for type specification because i do want there to be class capability with that syntax




--------------





foo| {[u64], [u1]} -> {[u1], [u1], [u2]}
foo =
    for n in IN[0] and IN[1] do
        if ((IN[0][n] % 2) == 0 && IN[1][n] == True) then
            OUT[0] = True
            OUT[1] = False
        else
            OUT[0] = False
            OUT[1] = True
        end
    end

    for n in OUT[2] do OUT[2][n] += (3 * OUT[0][n] + OUT[1][n]) end

end



print(foo([1,2,3,4], [0,1,1,0]){OUT[0]})

    // expected (array type): [0, 1, 0, 0]

print(foo([1,2,3,4], [0,1,1,0]){OUT[1]})

    // expected (array type): [1, 0, 1, 1]

print(foo([1,2,3,4], [0,1,1,0]){OUT[2]})

    // expected (array type): [1, 3, 1, 1]

print(foo([1,2,3,4], [0,1,1,0]){OUT[2], OUT[0]})

    // expected (collection type of arrays): {[1, 3, 1, 1], [0, 1, 0, 0]}

print(foo([1,2,3,4], [0,1,1,0]))

    // expected (collection type of arrays): {[0, 1, 0, 0], [1, 0, 1, 1], [1, 3, 1, 1]}


=========================================================================




// takes a number first out is if its even second is if its odd

fn foo | {u64} -> {u1, u1}
foo (x) =
    if ((x % 2) == 0) then
        return 1, 0
    else if ((x % 2) != 0) then
        return 0, 1
end

print(a, b : foo(2))




// in: x and y point
// out: 1:x 2:y 3:magnitude

fn magnitude | {u64, u64} -> {u64, u64, f64}
magnitude (x, y) =
    return x, y, sqrt((x ** 2) + (y ** 2))

print("%a %b %c", a, b, c) : magnitude(a, b) : io.inInt("please enter integer"), io.inInt("please enter integer")                // think of : like "inject right into left when using multiple returns"


// consider collection data type; input(), input is the same as {input(), input()} where the output of magnitude is {x, y, mag} like its just visual grouping
calculate(a, b, c) : magnitude(2, 3)




