const inf                       ='energy.in';
      ouf                       ='energy.out';
      maxn                      =251;

var   i,j,n,k,l,m               :longint;
      f                         :array[1..maxn,1..maxn]of longint;
      a                         :array[0..maxn]of longint;
      b                         :array[0..maxn]of longint;

procedure init;
 begin
   assign(input,inf);
   reset(input);
   readln(n);
   for i:=1 to n do
     read(a[i]);
   readln;
   for i:=1 to n do
     a[i+n]:=a[i];
   a[0]:=a[n];
   a[m+1]:=a[1];
   m:=n*2;
   for i:=1 to m do
     b[i]:=a[i+1];
   close(input);
 end;

procedure cal;
 var ans                :longint;
 begin
   fillchar(f,sizeof(f),0);
   for i:=1 to n-1 do
     begin
       for j:=1 to m-i do
         begin
           l:=j+i;
           for k:=j to l-1 do
             if f[j,k]+f[k+1,l]+b[k]*a[j]*b[l]>f[j,l] then
              f[j,l]:=f[j,k]+f[k+1,l]
                      +b[k]*a[j]*b[l];
         end;
     end;
   ans:=0;
   for i:=1 to n do
     if f[i,i+n-1]>ans then ans:=f[i,i+n-1];
   assign(output,ouf);
   rewrite(output);
   writeln(ans);
   close(output);
 end;

begin
  init; cal;
end.
