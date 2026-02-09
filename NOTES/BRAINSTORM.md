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


