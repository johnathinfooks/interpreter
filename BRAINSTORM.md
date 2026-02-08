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
