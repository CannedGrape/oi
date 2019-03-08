var n,i,j,ans:longint;a,g,h:array[1..100000]of longint;
f:array[0..100000,1..2]of longint;
function max(q,w:longint):longint;
begin
  if q>w then max:=q else max:=w;
end;
begin
assign(input,'flower.in');reset(input);
assign(output,'flower.out');rewrite(output);
        read(n);
        for i:=1 to n do
        read(a[i]);
        for i:=n downto 1 do
        begin
           for j:=i-1 downto 1 do
            if a[i]<a[j]then begin
                g[i]:=j;break;end;
           for j:=i-1 downto 1 do
            if a[i]>a[j] then begin
                h[i]:=j;break;end;
        end;
        f[1,1]:=1;f[0,1]:=-maxlongint;
        for i:=2 to n do
        begin
        f[i,1]:=max(f[i-1,1],f[g[i],2]+1);
        f[i,2]:=max(f[h[i],1]+1,f[i-1,2]);
        end;
        ans:=max(f[n,1],f[n,2]);
        for i:=1 to n do
        begin f[i,1]:=0;f[i,2]:=0;end;
        f[1,1]:=1;f[0,1]:=-999;
        for i:=2 to n do
        begin
          f[i,1]:=max(f[i-1,1],f[h[i],2]+1);
          f[i,2]:=max(f[g[i],1]+1,f[i-1,2]);
        end;
        ans:=max(f[n,1],f[n,2]);
        writeln(ans);
        close(input);close(output);
end.
