{$A+,B-,D+,E+,F-,G-,I-,L+,N-,O-,R-,S-,V+,X-}
{$M 65520,0,655360}

Program Stamp;
Const
  Maxn=40;
Var
  Value,BestValue       :       Array[1..Maxn] Of Integer;
  Max,N,K               :       Integer;

{If N=5,K=5 Value[]=(1,4,9,31,51), It returns 126, Got it?}
Function Cont(x:Integer):Integer;
Var
  I:Integer;
  CanGet:Array[0..10000] Of Boolean;
  Count:Array[1..Maxn] Of Integer;

Procedure UseIt(Num,Left:Integer);
Var
  I:Integer;
  Total:Integer;
Begin
  If Num=x+1 Then
  Begin
    Total:=0;
    For I:=1 to x Do Inc(Total,Value[i]*Count[I]);
    CanGet[Total]:=True;
    Exit;
  End;
  For I:=0 to Left Do
  Begin
    Count[Num]:=I;
    UseIt(Num+1,Left-I)
  End;
End;
Begin
  Fillchar(CanGet,SizeOf(CanGet),0);
  UseIt(1,n);
  I:=1; While CanGet[i] Do Inc(I); Cont:=I-1;
End;

Procedure Find(FindStart,ContStart,x:Integer);
Var
  I:Integer;
  ContMost:Integer;
Begin
  If x=k+1 Then
  Begin
    If Max < ContStart-1 Then
    Begin
      Max := ContStart-1;                      {Hey, ContStart is NOT the largest number we really got!}
      For I:=1 to K Do BestValue[I]:=Value[I]; {Copy to BestValue}
    End;
    Exit;
  End;

  I:=FindStart;
  While True Do
  Begin
    Value[x]:=i;
    ContMost:=Cont(x); {Calculate}
    Find(I+1,ContMost+1,x+1);
    If I+1>ContStart Then Exit Else Inc(I);
    {if I+1>ContStart we CANNOT get value Constart 'cause I will be bigger and bigger}
  End;
End;

Procedure Init;
Begin
  Max:=0;                       {Initialize}
  Write('N='); Readln(N);
  Write('K='); Readln(K);
  Value[1]:=1;                  {The 1st Stamp Must Be 1 ^_^}
End;

Procedure Answer;
Var I:Integer;
Begin
  For I:=1 to K Do Write(BestValue[I],' ');
  WriteLn;
  WriteLn('MAX=',Max);
End;

Begin
  Init;
  Find(2,n+1,2);                {Search From the 2nd Stamp}
  Answer;
End.
