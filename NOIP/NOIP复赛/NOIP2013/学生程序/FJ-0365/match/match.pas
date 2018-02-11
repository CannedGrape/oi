var t,ans,m,n,c,d,t1,t2,num1,num2,mid:int64; a,b,i,j:longint;
    a1,a2,b1,b2:array[1..100000] of int64;

    procedure try1(l,r:longint);
   var mid,i,j,t:longint;
    begin
     i:=l; j:=r; mid:=a1[(l+r) div 2];
      repeat
      while a1[i]<mid do inc(i);
      while a1[j]>mid do dec(j);
      if j>=i then begin  t:=a1[i]; a1[i]:=a1[j]; a1[j]:=t;
       inc(i); dec(j); end;
       until j<i;
       if i<r then try1(i,r);
       if j>l then try1(l,j);
    end;

     procedure try2(l,r:longint);
   var mid,i,j,t:longint;
    begin
     i:=l; j:=r; mid:=a2[(l+r) div 2];
      repeat
      while a2[i]<mid do inc(i);
      while a2[j]>mid do dec(j);
      if j>=i then begin  t:=a2[i]; a2[i]:=a2[j]; a2[j]:=t;
       inc(i); dec(j); end;
       until j<i;
       if i<r then try2(i,r);
       if j>l then try2(l,j);
    end;



     begin assign(input,'match.in'); reset(input);
           assign(output,'match.out'); rewrite(output);
     ans:=0;
     readln(n);
      for i:=1 to n do begin read(a1[i]); b1[i]:=a1[i]; end; try1(1,n);
      for j:=1 to n do begin read(a2[j]); b2[j]:=a2[j]; end; try2(1,n);


    for i:=1 to n do
      begin t1:=a1[i]; t2:=a2[i];
       for a:=1 to n do if b1[a]=t1 then begin num1:=a; break; end;
       for b:=1 to n do if b2[b]=t2 then begin num2:=b; break; end;
       if num1>num2 then  ans:=ans+num1-num2 else ans:=ans+num2-num1;

      end;



   write((ans div 2) mod 99999997);  close(input); close(output);

    end.








