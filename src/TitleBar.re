open BsReactNative;

let component = ReasonReact.statelessComponent("TitleBar");

let style = Style.(style([
    height(Pt(50.)),
    width(Pct(100.)),
    backgroundColor(String("#ff6600"))
]));

let make = (_children) =>{
    ...component,
    render: (_self) =>
        <View style>
        </View>
}