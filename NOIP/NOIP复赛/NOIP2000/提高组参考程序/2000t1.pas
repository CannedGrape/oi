const
  maxn=50;
  ch:string[20]='0123456789ABCDEFGHIJ';
var
  i,j,n,m,k:longint;
  bit:array[0..maxn] of longint;

begin
  while not eof(input) do
  begin
    readln(n,m);
    i:=0; k:=n;
    while (k<0)or(k>=-m) do
    begin
      bit[i]:=k mod m;
      k:=k div m;
      if bit[i]<0 then
      begin
        bit[i]:=bit[i]-m;
        k:=k+1;
      end;
      inc(i);
    end;
    bit[i]:=k;
    for j:=i downto 0 do
      write(ch[bit[j]+1]);
    writeln;
  end;
end.
