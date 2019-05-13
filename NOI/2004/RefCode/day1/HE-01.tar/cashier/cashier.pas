program cashier;
const
limit   = 300001;
var
c       : char;
a       : array[1..300001] of longint;
min,n   : longint;
delta   : longint;
k,i,ti  : longint;
getout  : longint;
inhere  : longint;
function lowbit(tm: longint): longint;
   begin
   lowbit:= tm and not (tm-1);
   end;
procedure insert(tm: longint);
   begin
   while tm<=limit do begin
      inc(a[tm]);
      tm:= tm+lowbit(tm);
      end;
   end;
procedure delete(tm: longint);
   begin
   while tm<=limit do begin
      dec(a[tm]);
      tm:= tm+lowbit(tm);
      end;
   end;
function query(tk: longint): longint;
   var
   rv           : longint;
   step         : longint;
   nowv         : longint;
   last         : longint;
   begin
   if inhere-getout<tk then begin
      query:= -1; exit;
      end;
   tk:= inhere-getout+1-tk;
   step:= 1 shl 18; nowv:= 0; rv:= 0;
   while (nowv<>tk)and(step<>0) do begin
       while (a[rv+step]+nowv>=tk)and(step>0) do begin
          if a[rv+step]+nowv>=tk then last:= rv+step;
          step:= step shr 1;
          end;
       if step=0 then continue;
       rv:= rv+step;
       nowv:= a[rv]+nowv;
       step:= step shr 1;
       end;
   query:= last+delta;
   end;
begin
assign(input,'cashier.in'); reset(input);
assign(output,'cashier.out'); rewrite(output);
fillchar(a,sizeof(a),0);
readln(n,min);
getout:= 0; delta:= -100001; inhere:= 0;
for i:= 1 to n do begin
   read(c); readln(k);
   case c of
      'I': begin
             inc(inhere);
             if k<min then inc(getout)
             else
                insert(k-delta);
           end;
      'A': begin
             delta:= delta+k;
           end;
      'S': begin
             for ti:= min-delta to min-delta+k-1 do begin
                while a[ti]>0 do begin
                   inc(getout); delete(ti);
                   end;
                end;
             delta:= delta-k;
           end;
      'F': begin
             writeln(query(k));
           end;
      end;
   end;
writeln(getout);
close(output);
end.
