program number;
  var a,f:array[1..1000000]of longint;
  var n,p:integer;
procedure init;
  var i:integer;
  begin
    assign(input,'number.in');reset(input);
    readln(n,p);
    for i:=1 to n do read(a[i]);
    close(input);
  end;
function max(a,b:integer):integer;
  begin if a>b then exit(a) else exit(b); end;
procedure work;
  var i,j,temp:longint;
  begin
    for i:=1 to n do f[i]:=-maxlongint;
    for i:=1 to n do
    begin
      temp:=0;
      for j:=i to n do
      begin
        temp:=temp+a[j];
        f[j]:=max(f[j],temp);
      end;
    end;
  end;
procedure print;
  var i:longint;
  var ans:longint;
  begin
    a[1]:=f[1] mod p;
    ans:=f[1] mod p;
    for i:=2 to n do
    begin
      a[i]:=(a[i-1]+f[i-1])mod p;
      ans:=max(ans,a[i]);
    end;
    assign(output,'number.out');rewrite(output);
    writeln(ans mod p);
    close(output);
  end;
begin
  init;
  work;
  print;
end.
