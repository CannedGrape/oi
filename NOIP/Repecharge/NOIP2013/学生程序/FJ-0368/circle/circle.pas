program circle;
var n,m,x,k,i,yu,d:longint;
t:string;
begin
assign(input,'circle.in');
reset(input);
assign(output,'circle.out');
rewrite(output);
read(n,m,k,x);d:=1;
yu:=n mod 10;
if yu > 0 then
   begin
     if k<6 then
       begin
        for i:=1 to k do d:=d*10;
        if d<n then yu:=d
       end
      else
        begin
         str(n,t);
         while k>(length(t)+1) do k:=k-length(t);
         yu:=k mod n;
        end;
         for i:=1 to yu do
          begin
          if x<m then x:=x+n;
          x:=x-m;
          end;
          dec(x);
   end;
      writeln(x);
close(input);close(output);
end.
