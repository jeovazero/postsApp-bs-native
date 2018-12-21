open BsReactNative;

let component = ReasonReact.statelessComponent("FloatButton");

let floatButton = Style.(style([
    position(Absolute),
    bottom(Pt(20.)),
    right(Pt(20.)),
    height(Pt(50.)),
    width(Pt(50.)),
    borderRadius(50.),
    backgroundColor(String("#ffffff")),
    display(Flex),
    justifyContent(Center),
    alignItems(Center),
    elevation(5.),
    shadowColor(String("#000000")),
    shadowOffset(~height=3. , ~width=2.),
    shadowOpacity(0.3)
]));

let textFloatButton = Style.(style([
    color(String("rgb(175, 100, 200)")),
    fontSize(Float(40.))
]))

let make = (~onPress , _children) => {
    ...component,
    render: (_self) => {
        <View style=floatButton>
        <TouchableOpacity onPress=(() => onPress())>
            <Text style=textFloatButton> (ReasonReact.string("+")) </Text>
        </TouchableOpacity>
        </View>
    }
}