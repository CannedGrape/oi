const inf                       ='digital.in';
      ouf                       ='digital.out';
      maxn                      =512;
      pw                        :array[1..9]of longint=(2,4,8,16,32,64,128,256,512);
      mol                       =1000000;

type  bignum                    =array[0..50]of longint;

var   k,w,n,i,p,j               :longint;
      f                         :array[boolean,0..maxn]of bignum;
      ans                       :bignum;

procedure init;
 begin
   assign(input,inf);
   reset(input);
   readln(k,w);
   n:=1;
   for i:=1 to k do
     n:=n*2;
   close(input);
 end;

procedure hiadd(var a,b:bignum);
 var i,j,n,tmp                  :longint;
     ta                         :bignum;
 begin
   if a[0]<b[0] then a[0]:=b[0];
   for i:=1 to a[0] do
     a[i]:=a[i]+b[i];
   for i:=1 to a[0] do
     begin
       tmp:=a[i] div mol; inc(a[i+1],tmp);
       a[i]:=a[i] mod mol;
     end;
   if a[a[0]+1]>0 then inc(a[0]);
 end;

procedure cal;
 var      now,last      :boolean;
          change        :boolean;
          max           :longint;

 begin
   p:=k;
   now:=true; last:=false;
   fillchar(f,sizeof(f),0);
   for i:=0 to n do
     begin
       f[now,i][0]:=1; f[now,i][1]:=1;
     end;
   dec(n);
   if w>k*n then w:=k*n;
   ans[0]:=1; ans[1]:=0;
   repeat
     now:=not now; last:=not last;
     fillchar(f[now],sizeof(f[now]),0);
     change:=false;
     inc(p,k);
     if p>w then
      begin
        dec(p,k); max:=w-p; p:=w;
      end
     else max:=k;
     hiadd(f[now,n-1],f[last,n]);
     for i:=n-2 downto 0 do
       begin
         f[now,i]:=f[now,i+1];
         hiadd(f[now,i],f[last,i+1]);
       end;
     if p>2*k then hiadd(ans,f[now,0]);
   until p=w;
   for i:=1 to pw[max]-1 do
     hiadd(ans,f[now,i]);
   assign(output,ouf);
   rewrite(output);
   n:=ans[0];
   write(ans[n]);
   for i:=n-1 downto 1 do
     begin
       max:=mol div 10;
       while max<>0 do
        begin
          write(ans[i] div max mod 10);
          max:=max div 10;
        end;
     end;
   writeln;
   close(output);
 end;

begin
  init; cal;
end.
