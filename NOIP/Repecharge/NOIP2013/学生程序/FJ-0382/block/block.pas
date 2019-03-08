program block;

var lob,loe,l,n,i:longint;
    h,x:array[-100..101000] of integer;
    s,k:longint;
    flag:boolean;



    procedure findl;
    var  a,b,c,a1,b1:longint;
         fof,foe:boolean;
    begin
    a1:=0;
    fof:=false;
    for a:=1 to n do
      if x[a]<>h[a] then if fof=false then
                                           begin
                                             fof:=true;
                                             lob:=a;
                                             a1:=a;
                                             break;
                                           end;


    foe:=false;
    for b:=a1 to n do
      begin
      if x[b]=h[b] then
                       begin
                         loe:=b-1;
                         foe:=true;
                         break;
                       end;
      if (b=n) and (foe=false) then loe:=b;
     end;

   end;


{main}


begin
assign(input,'block.in');
reset(input);
assign(output,'block.out');
rewrite(output);

{duru}
read(n);
for i:=1 to n do read(h[i]);

fillchar(x,sizeof(x),0);

s:=0;
repeat
findl;
for i:=lob to loe do x[i]:=x[i]+1;
s:=s+1;

flag:=true;
for i:=1 to n do  if x[i]<>h[i] then begin flag:=false; break; end;

if s>1000000 then begin k:=s div 1000000; s:=s mod 1000000; end;
until flag=true;

write(s+1000000*k);
close(input);
close(output);

end.
