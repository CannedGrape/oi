{$r-,q-,s-,n+,g+}
program FenQuPrepare_Day5_Task1_FQ2000P1;
const
  fn_in='input.txt';
  maxa=100;
  stri:string[20]='0123456789ABCDEFGHIJ';
var
  n,r:longint;
  a:array[1..maxa] of integer;

  procedure solve;
  var l,i,j:Integer;
  begin
    write(n,'=');
    r:=-r;
    l:=0;
    while(n<>0) do
    begin
      inc(l);
      a[l]:=(r+(n mod r)) mod r;
      n:=(n-a[l]) div (-r);
    end;
    for i:=l downto 1 do
      write(stri[a[i]+1]);
    writeln('(base ',-r,')');
  end;

  begin
{    assign(input,fn_in);
    reset(input);}
    readln(n,r);
    while(r<>0) do
    begin
      solve;
      readln(n,r);
    end;
  end.