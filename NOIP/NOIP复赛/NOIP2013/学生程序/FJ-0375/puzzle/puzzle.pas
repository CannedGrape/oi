begin
    assign(input,'puzzle.out'); reset(input);
    assign(output,'puzzle.in'); rewrite(output);
    write(-1);
    close(input); close(output);
    end.