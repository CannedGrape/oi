program flower;
const maxn=100000;
var n,m,temp:longint;
ans:longint;
i,j:longint;
a:array[1..maxn]of longint;
f,g:array[1..maxn,0..1]of longint;

begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);

  readln(n);
  for i:=1 to n do
    read(a[i]);
  
  ans:=1;
  f[1,1]:=1;
  f[1,0]:=0;
  for i:=2 to n do begin
    f[i,1]:=1;
    for j:=1 to i-1 do begin
      if a[i]>a[j] then begin
        if f[j,1]>0 then begin
          if f[i,0]<f[j,1]+1 then begin
            f[i,0]:=f[j,1]+1;
          end;
        end;
      end
      else if a[i]<a[j] then begin
        if f[j,0]>0 then begin
          if f[i,1]<f[j,0]+1 then begin
            f[i,1]:=f[j,0]+1;
          end;
        end;
      end;
    end;
    if f[i,0]>ans then ans:=f[i,0];
    if f[i,1]>ans then ans:=f[i,1];
  end;
  g[1,1]:=1;
  g[1,0]:=0;
  for i:=2 to n do begin
    g[i,1]:=1;
    for j:=1 to i-1 do begin
      if a[i]<a[j] then begin
        if g[j,1]>0 then begin
          if g[i,0]<g[j,1]+1 then begin
            g[i,0]:=g[j,1]+1;
          end;
        end;
      end
      else if a[i]>a[j] then begin
        if g[j,0]>0 then begin
          if g[i,1]<g[j,0]+1 then begin
            g[i,1]:=g[j,0]+1;
          end;
        end;
      end;
    end;
    if g[i,0]>ans then ans:=g[i,0];
    if g[i,1]>ans then ans:=g[i,1];
  end;

  write(ans);


  close(input);close(output);
end.
