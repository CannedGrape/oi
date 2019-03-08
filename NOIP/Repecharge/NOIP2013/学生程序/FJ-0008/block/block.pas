var n,i,sum:longint;h:array[1..100000]of longint;
procedure dfs(l,r:longint);
var y,k,min:longint;
begin
        if l>r then exit;
        min:=maxlongint;
        for k:=l to r do
        if min>h[k] then begin min:=h[k];y:=k;end;
        inc(sum,min);
        for k:=l to r do
         dec(h[k],min);
        dfs(l,y-1);dfs(y+1,r);
end;
begin
        assign(input,'block.in');reset(input);
        assign(output,'block.out');rewrite(output);
        read(n);
        for i:=1 to n do
                read(h[i]);
        dfs(1,n);
        writeln(sum);
        close(input);close(output);
end.
