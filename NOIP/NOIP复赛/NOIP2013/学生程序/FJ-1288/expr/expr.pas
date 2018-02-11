var
f:string;
s:array[1..100000] of longint;
a,b,i,t:longint;
begin
  assign(input,'expr.in');
  reset(input);
  assign(output,'expr.out');
  rewrite(output);
  read(f);
  a:=length(f);

  for i:=1 to a do
    if f[i]='0' then s[i]:=0
        else if f[i]='1' then s[i]:=1
        else if f[i]='2' then s[i]:=2
        else  if f[i]='3' then s[i]:=3
        else   if f[i]='4' then s[i]:=4
        else   if f[i]='5' then s[i]:=5
        else    if f[i]='6' then s[i]:=6
        else  if f[i]='7' then s[i]:=7
        else   if f[i]='8' then s[i]:=8
        else  if f[i]='9' then s[i]:=9;




   for i:=1 to a do
     if f[i]='*' then
                     begin
                     s[i+1]:=s[i-1]*s[i+1];

                     end;

   if f[2]='+' then b:=b+s[1];
   for i:=1 to a do
     if (f[i]='+') and (f[i+2]<>'*') then  begin b:=b+s[i+1];end
       else if f[i+2]='*' then b:=b+s[i+3];


   writeln(b);


  close(input);
  close(output);
end.
