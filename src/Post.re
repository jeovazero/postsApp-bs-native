open BsReactNative;

type post = {
  author: string,
  text: string
};

let component = ReasonReact.statelessComponent("Post");

let make = (~post as {author, text}, _children) => {
    ...component,
    render: (_self) => {
        <View>
          <View>
            <Text> (ReasonReact.string(text)) </Text>
          </View>
          <View>
            <Text>
              (ReasonReact.string("by " ++ author))
            </Text>
          </View>
        </View>
    }
}