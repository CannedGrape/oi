var
        run:array[0..1000000]of int64;
        fen:array[1..1000000]of int64;
        te:array[1..1000000]of int64;
        zhi:array[1..1000000]of int64;
        n,p,i,j,k:longint;
        max:int64;
begin
        assign(input,'number.in');
        assign(output,'number.out');
        reset(input);
        rewrite(output);
        readln(n,p);for i:=1 to n do te[i]:=-2147483648;
        for i:=1 to n do read(zhi[i]);
        for i:=1 to n do begin      {qidian}
                for j:=i to n do
                        run[j]:=run[j-1]+zhi[j];
                for j:=i to n do
                        for k:=j to n do
                        if run[j]>te[k] then te[k]:=run[j];
        end;
        fen[1]:=te[1];
        for i:=2 to n do fen[i]:=fen[i-1]+te[i-1]; max:=-2147483648;
        for i:=1 to n do if max<fen[i] then max:=fen[i];
        writeln(max mod p);
        close(input);close(output);
end.