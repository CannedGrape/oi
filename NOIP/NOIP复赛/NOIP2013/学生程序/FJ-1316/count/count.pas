program count (input,output);
var
 n,x,a,d,j,z,q,w,e:longint;
 k:array [1..20] of integer;
begin
 assign(input,'count.in');
 reset(input);
 assign(output,'count.out');
 rewrite(output);
 readln(n,x);
 a:=0;
 for j:=1 to n do
  begin
   if (j<=9) and (x=j) then
    a:=a+1;
   if (j>=10) and (j<=99) then
    begin
     k[1]:=j div 10;
     d:=j mod 10;
     if x=k[1] then
      a:=a+1;
     if x=d then
      a:=a+1
    end;
   if (j>=100) and (j<=999) then
    begin
     k[2]:=j div 100;
     k[3]:=(j-k[2]*100) div 10;
     k[4]:=(j-k[2]*100) mod 10;
     for z:=2 to 4 do
       if x=k[z] then
        a:=a+1
    end;
   if (j>=1000) and (j<=9999) then
    begin
     k[5]:=j div 1000;
     k[6]:=(j-k[5]*1000) div 100;
     k[7]:=(j-k[5]*1000-k[6]*100) div 10;
     k[8]:=(j-k[5]*1000-k[6]*100) mod 10;
     for q:=5 to 8 do
       if x=k[q] then
        a:=a+1
    end;
   if (j>=10000) and (j<=99999) then
    begin
     k[9]:=j div 10000;
     k[10]:=(j-k[9]*10000) div 1000;
     k[11]:=(j-k[9]*10000-k[10]*1000) div 100;
     k[12]:=(j-k[9]*10000-k[10]*1000-k[11]*100) div 10;
     k[13]:=(j-k[9]*10000-k[10]*1000-k[11]*100) mod 10;
     for w:=9 to 13 do
      if x=k[w] then
       a:=a+1
    end;
   if (j>=100000) and (j<=999999) then
    begin
     k[14]:=j div 100000;
     k[15]:=(j-k[14]*100000) div 10000;
     k[16]:=(j-k[14]*100000-k[15]*10000) div 1000;
     k[17]:=(j-k[14]*100000-k[15]*10000-k[16]*1000) div 100;
     k[18]:=(j-k[14]*100000-k[15]*10000-k[16]*1000-k[17]*100) div 10;
     k[19]:=(j-k[14]*100000-k[15]*10000-k[16]*1000-k[17]*100) mod 10;
     for e:=14 to 19 do
      if x=k[e] then
       a:=a+1
    end;
  end;
   if (j=1000000) and (x=1) then
    a:=a+1;
 write(a);
 close(input);
 close(output);
end.





