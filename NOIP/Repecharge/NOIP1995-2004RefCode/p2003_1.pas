program p2003_1;

procedure tran(fen:integer);
var temp:char;
    w,L:integer;
    first:boolean;
begin
    w:=0;L:=0;
    first:=true;
    read(temp);
    while temp<>'E' do begin
        if temp='W' then
           w:=w+1
        else if temp='L' then
           L:=L+1;
        if ((w>=fen) or (L>=fen)) and (abs(w-L)>=2) then begin
             writeln(w,':',l);
             w:=0;L:=0;
             first:=false;
           end;
        read(temp);
    end;
    writeln(w,':',L);
end;

begin
     assign(input,'table.in');
     reset(input);
     assign(output,'table.out');
     rewrite(output);
     tran(11);
     close(input);
     writeln;
     assign(input,'table.in');
     reset(input);
     tran(21);
     close(input);
     close(output);
end.
