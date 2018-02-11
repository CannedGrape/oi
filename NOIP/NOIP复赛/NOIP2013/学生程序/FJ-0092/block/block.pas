var a:array[0..100000] of longint;
 i,j,k,n,m:longint;
 min,tmphead,tmpuil:longint;
   tot:int64;
begin
assign(input,'block.in');
assign(output,'block.out');
reset(input);
rewrite(output);
  readln(n);


 for i:=1 to n do
 read(a[i]);
 tmphead:=1;
 tmpuil:=n;
 repeat
   begin

    while a[tmphead]=0 do inc(tmphead);
    while a[tmpuil]=0  do dec(tmpuil);
        min:=999999;
    for i:=tmphead to tmpuil do
     begin
       if a[i]=0  then
        begin
        inc(tot,min);
                for j:=tmphead to i-1 do
                   begin dec(a[j],min);   end;
                 break;
                end
            else
                 if a[i]<min then min:=a[i];
            if i=tmpuil then begin
                    inc(tot,min);
                     for j:=tmphead to i do
                    dec(a[j],min);   end;



      end;

    end;

 until  tmpuil<=tmphead;
 writeln(tot);
 close(input);
 close(output);
 end.

