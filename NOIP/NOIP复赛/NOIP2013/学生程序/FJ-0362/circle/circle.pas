var n,m,x:longint;
    k,i,h,t:int64;

begin
 assign(input,'circle.in');  reset(input);
 assign(output,'circle.out');  rewrite(output);
 readln(n,m,k,x
 );
 h:=1; i:=1;
  repeat
   h:=h*10;
   inc(i);
  until i>k;
 t:=1;
  repeat
   x:=x+m;
   x:=x mod n;
   inc(t);
  until t>h;
 write(x);

 close(input);  close(output);
 end.
