type ar=array[0..100005,1..2] of longint;
var i,j,k,t,m,n,x,y,z,ans,r,a1,b1:longint;
    a,b:ar;
    c:array[0..100005,1..3] of longint;
    f:array[0..100005] of boolean;
procedure shift1(i,n:longint);
  var j,x,y:longint;
  begin
   j:=i+i; x:=a[i,1]; y:=a[i,2];
   while j<=n do
    begin
     if (j<n) and (a[j,1]>a[j+1,1]) then inc(j);
     if x>a[j,1] then
      begin
       a[j div 2,1]:=a[j,1];
       a[j div 2,2]:=a[j,2];
       j:=j+j;
      end else break;
    end;
   a[j div 2,1]:=x; a[j div 2,2]:=y;
  end;
procedure sort1;
  var i,j,k,t:longint;
  begin
   for i:=n div 2 downto 1 do shift1(i,n);
   for i:=n downto 2 do
    begin
     t:=a[1,1]; a[1,1]:=a[i,1]; a[i,1]:=t;
     t:=a[1,2]; a[1,2]:=a[i,2]; a[i,2]:=t;
     shift1(1,i-1);
    end;
  end;
procedure shift2(i,n:longint);
  var j,x,y:longint;
  begin
   j:=i+i; x:=b[i,1]; y:=b[i,2];
   while j<=n do
    begin
     if (j<n) and (b[j,1]>b[j+1,1]) then inc(j);
     if x>b[j,1] then
      begin
       b[j div 2,1]:=b[j,1];
       b[j div 2,2]:=b[j,2];
       j:=j+j;
      end else break;
    end;
   b[j div 2,1]:=x; b[j div 2,2]:=y;
  end;
procedure sort2;
  var i,j,k,t:longint;
  begin
   for i:=n div 2 downto 1 do shift2(i,n);
   for i:=n downto 2 do
    begin
     t:=b[1,1]; b[1,1]:=b[i,1]; b[i,1]:=t;
     t:=b[1,2]; b[1,2]:=b[i,2]; b[i,2]:=t;
     shift2(1,i-1);
    end;
  end;
begin
 assign(input,'match.in'); reset(input);
 assign(output,'match.out'); rewrite(output);
 readln(n);
 for i:=1 to n do begin read(a[i,1]); a[i,2]:=i; end;
 readln;
 for i:=1 to n do begin read(b[i,1]); b[i,2]:=i; end;
 readln;
 sort1;
 sort2;
 k:=0; t:=0;
 for i:=1 to n do if a[i,2]<>b[i,2] then
  begin
   inc(t);
   c[t,1]:=a[i,2]; c[t,2]:=b[i,2]; c[t,3]:=i;
  end;
 fillchar(f,sizeof(f),true);
 k:=t div 2;  r:=t;
 for i:=1 to k do
  begin
   if r=0 then break;
   j:=1;
   while not f[j] do inc(j);
   x:=c[j,1]; y:=c[j,2]; z:=c[j,3]; inc(j); dec(r); a1:=0; b1:=0;
   while j<=t do
    begin
     if (x=c[j,2]) and (y=c[j,1]) then begin dec(r); break; end
      else
     if (x<>c[j,2]) and (y<>c[j,1]) then inc(j)
      else
     if (x=c[j,2]) and (y<>c[j,1]) then
      begin
       x:=c[j,1];
       ans:=(ans+((j-z) mod 99999997)+((j-z-1) mod 99999997)) mod 99999997;
       z:=c[j,3];
       inc(j);  dec(r); inc(a1);
      end
      else
     begin
      y:=c[j,2];
      ans:=(ans+((j-z) mod 99999997)+((j-z-1) mod 99999997)) mod 99999997;
      z:=c[j,3];
      inc(j);
      dec(r);
      inc(b1);
      end;
    end;
   ans:=(ans+((j-z) mod 99999997)+((j-z-1) mod 99999997)) mod 99999997;
  end;
 writeln(ans);
 close(input); close(output);
end.






