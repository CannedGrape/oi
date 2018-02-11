



var b,a:array[0..110000]of longint;
c:array[0..110000]of longint;
f:array[0..1100,0..1100]of longint;


ave,sum,i,j,k,m,n:longint;
number:longint;
tot:longint;
begin
  assign(input,'match.in');
  assign(output,'match.out');
  reset(input);
  rewrite(output);
readln(n);
for i:=1 to n do
read(a[i]);
for i:=1 to n do
read(b[i]);
for i:=1 to n do
c[i]:=a[i]-b[i];
tot:=0;
sum:=0;
i:=1; j:=n;
    repeat
     begin
      while c[i]=0  do inc(i);
      while c[j]=0 do dec(j);
        if i<j then
        begin
           inc(tot);
           tot:=tot mod  99999997;
           c[i]:=c[i]+c[j];

            while
            c[i]=0 do inc(i);


         dec(j);
          end;
       end;
     until i>=j;
    writeln(tot);
    close(input);
    close(output);
    end.