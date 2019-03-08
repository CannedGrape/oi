var a,h,t,w:array[0..100000] of longint;
    i,n,num:longint;
 procedure add(l,r:longint);
   var m:longint;
 begin
   for m:=l to r do
     inc(a[m]);
 end;

 function pd(o:longint) :boolean;
   var q,e,q1,e1:longint;
 begin
   pd:=true;
   for q:=1 to o do
     for q1:=t[q] to w[q] do
       if a[q1]<>h[q1] then
         begin
           pd:=false;
           break;
         end;
 end;
 procedure lr;
   var x,y,z,s,k,p,temp:longint;
 begin
   x:=1;
   for i:=n downto 1 do
     if h[i]<>a[i] then begin p:=i; break;  end;
   repeat
     z:=w[x-1]+2;
     while a[z]=h[z] do inc(z);
     t[x]:=z;
     s:=z;
     while a[s]<>h[s] do inc(s);
     w[x]:=s-1;
     inc(x);
   until s>p;
   for i:=1 to x-1 do
     begin
       add(t[i],w[i]);
       inc(num);
     end;
   if pd(x-1)=false  then lr;
 end;


 begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
   read(n);
   for i:=1 to n do
     read(h[i]);
   w[0]:=-1;
   lr;
   write(num);
   close(input);
   close(output);
   end.
