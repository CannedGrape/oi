program t2001_3;
type arrc=array[1..6] of string;
var m,p,p1,k,s:integer;
    i,j,u,v,r:integer;
    b:arrc;
    temp,a:string;
    f:array[1..200,1..200,1..2]of integer;

function count(ss:string;b:arrc;nb:integer):integer;
var sum,i,j,u,v:integer;
begin
     sum:=0;
     for i:=1 to length(ss) do
       for j:=1 to nb do
            if length(ss)-i+1>=length(b[j]) then begin
                u:=i;v:=1;
                while (v<=length(b[j])) and (ss[u]=b[j][v]) do begin
                     u:=u+1;v:=v+1;end;
                if v>length(b[j]) then begin sum:=sum+1;break;end;
            end;
     count:=sum;
end;

begin
     assign(input,'input3.dat');
     reset(input);
     assign(output,'output3.dat');
     rewrite(output);
         readln(p,k);
         for i:=1 to p do begin
            readln(b[1]);
            for j:=1 to 20 do
               a[(i-1)*20+j]:=b[1][j];
           end;
         a[0]:=chr(p*20);
         m:=length(a);
         readln(s);
         for i:=1 to s do readln(b[i]);
{caculate start value}
        for i:=1 to m do
          for j:=1 to m do
            for u:=1 to 2 do f[i,j,u]:=0;

        for i:=1 to m do {m:total charters}
           for j:=i to m do begin
              for u:=i to j do
                 temp[u-i+1]:=a[u];{a:input string,n lines}
              temp[0]:=chr(j-i+1);
              f[i,j,1]:=count(temp,b,s);
              f[i,j,2]:=f[i,j,1];
           end;
{caculate}
        for u:=2 to k do  {k parts}
            for i:=1 to m-u+1 do
               for j:=m downto i+u-1 do begin
                   f[i,j,2]:=0;
                   for r:=i+u-1 to j do
                      if f[i,j,2]<f[i,r-1,2]+f[r,j,1] then
                         begin f[i,j,2]:=f[i,r-1,2]+f[r,j,1];end;
               end;
        writeln(f[1,m,2]);
        close(output);
    close(input);
end.
