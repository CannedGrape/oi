{$R+,Q+,S+}
var two:array[1..40] of integer;
    mm,ten:int64;
    n,m,k,x,lt,i:longint;

procedure change_two(x:longint);
 var k:longint;
 begin
   k:=x;
   lt:=0;
   while k<>0 do
    begin
      inc(lt);
      two[lt]:=k mod 2;
      k:=k div 2;
    end;
 end;

begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);
  m:=m mod n;
  if k<>0 then
   begin
     fillchar(two,sizeof(two),0);
     change_two(k);
     ten:=10 mod n;
     mm:=1;
     for i:=1 to lt do
      begin
        if two[i]=1 then
        mm:=(mm*ten) mod n;
        ten:=(ten*ten) mod n;
      end;
     mm:=(mm*m) mod n;
     x:=(x+mm) mod n;
     write(x);
   end
  else write((x+m) mod n);
  close(input);close(output);
end.

