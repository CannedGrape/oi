var n,i,top:longint;sum:int64;
q,h:array[0..100001]of longint;
function max(o,p:longint):longint;
begin
        if o>p then exit(o);exit(p);
end;
begin
        assign(input,'block.in');reset(input);
        assign(output,'block.out');rewrite(output);
        readln(n);
        for i:=1 to n do
                read(h[i]);
        h[n+1]:=0;
        q[1]:=0;
        top:=1;
        for i:=1 to n+1 do
                begin
                         while q[top]>h[i] do begin inc(sum,q[top]-max(h[i],q[top-1]));dec(top); end;
                         if h[i]>q[top] then begin inc(top);q[top]:=h[i]; continue;end;
                end;
        writeln(sum);
        close(input);close(output);
end.
