var a,c,d:array[1..10000] of longint;
    q,i,n,v,m,t,g:longint;
procedure gzn(l,r:longint);
var s,u,j,o:longint;
begin
    s:=-10000;
    while l<=r do
    begin
    o:=l;
    while o<=r do
          begin
              u:=0;
              for j:=o to r do
                  begin
                      u:=u+a[j];
                      if u>s then s:=u;
                  end;
              inc(o);
          end;
    inc(l);
    dec(r);
    end;
    inc(q);
    c[q]:=s;
end;
begin
    assign(input,'number.in'); reset(input);
    assign(output,'number.out'); rewrite(output);
    readln(n,m);
    for i:=1 to n do
        begin
            read(a[i]);
            gzn(1,i);
        end;
   d[1]:=c[1];
   for i:=1 to n-1 do
       begin
       t:=t+c[i];
       d[i+1]:=t+a[i+1]-i;
       end;
   g:=-10000;
   for i:=1 to n do
       if g<d[i] then g:=d[i];
   writeln(g mod m);
   close(input);
   close(output);
end.
