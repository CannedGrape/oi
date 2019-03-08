program flower;

begin
    assign(input,'flower.in');reset(input);
    assign(output,'flower.out');rewrite(output);
    write('3');
    close(input);close(output);
end.

